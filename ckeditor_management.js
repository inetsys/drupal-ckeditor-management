var ckeditor_management = Drupal.settings.ckeditor_management || {};

CKEDITOR.on('dialogDefinition', function(ev){

	var dialogName = ev.data.name;
	var dialogDefinition = ev.data.definition

	if(dialogName == 'link'){
		var config = ckeditor_management.link || {};

		// Anchor options
		var anchor = config.anchor || {};
		if(anchor){
			if(typeof anchor.name != 'undefined' && !anchor.name){
				dialogDefinition.getContents('info').remove('anchorName');
			}
			if(typeof anchor.id != 'undefined' && !anchor.id){
				dialogDefinition.getContents('info').remove('anchorId');
			}
		}

		// Target
		var target = config.target || {};
		if(target){
			if(typeof target.enable != 'undefined' && !target.enable){
				dialogDefinition.removeContents('target');
			}else if(typeof target.options != 'undefined'){
				var clean = {};
				var all_items = dialogDefinition.getContents('target').get('linkTargetType').items;
				var label, value;
				for(i in all_items){
					label = all_items[i][0];
					value = all_items[i][1];
					clean[value] = label;
				}
				for(j in target.options){
					var active = target.options[j];
					if(!active){
						delete clean[j];
					}
				}

				var options = [];
				for(k in clean){
					options.push([clean[k], k]);
				}
				dialogDefinition.getContents('target').get('linkTargetType').items = options;
			}
		}

		// Advanced features
		var advanced = config.advanced || {};
		if(advanced){
			if(typeof advanced.enable != 'undefined' && !advanced.enable){
				dialogDefinition.removeContents('advanced');
			}
		}
	}

	if(dialogName == 'image'){
		var config = ckeditor_management.image || {};

		// Image size
		var size = config.size || {};
		if(size){
			if(typeof size.enable != 'undefined' && !size.enable){
				dialogDefinition.getContents('info').remove('txtWidth');
				dialogDefinition.getContents('info').remove('txtHeight');
				dialogDefinition.getContents('info').remove('ratioLock');
			}else if(typeof size.width != 'undefined' && !size.width){
				dialogDefinition.getContents('info').remove('txtWidth');
				dialogDefinition.getContents('info').remove('ratioLock');
			}else if(typeof size.height != 'undefined' && !size.height){
				dialogDefinition.getContents('info').remove('txtHeight');
				dialogDefinition.getContents('info').remove('ratioLock');
			}
		}

		// Border
		var border = config.border || {};
		if(border){
			if(typeof border.enable != 'undefined' && !border.enable){
				dialogDefinition.getContents('info').remove('txtBorder');
			}
		}

		// Margin
		var margin = config.margin || {};
		if(margin){
			if(typeof margin.enable != 'undefined' && !margin.enable){
				dialogDefinition.getContents('info').remove('txtHSpace');
				dialogDefinition.getContents('info').remove('txtVSpace');
			}else if(typeof margin.horizontal != 'undefined' && !margin.horizontal){
				dialogDefinition.getContents('info').remove('txtHSpace');
			}else if(typeof margin.vertical != 'undefined' && !margin.vertical){
				dialogDefinition.getContents('info').remove('txtVSpace');
			}
		}

		// Link
		var link = config.link || {};
		if(link){
			if(typeof link.enable != 'undefined' && !link.enable){
				dialogDefinition.removeContents('Link');
			}else if(typeof link.options != 'undefined'){
				var clean = {};
				var all_items = dialogDefinition.getContents('Link').get('cmbTarget').items;
				var label, value;
				for(i in all_items){
					label = all_items[i][0];
					value = all_items[i][1];
					clean[value] = label;
				}
				for(j in link.options){
					var active = link.options[j];
					if(!active){
						delete clean[j];
					}
				}

				var options = [];
				for(k in clean){
					options.push([clean[k], k]);
				}
				dialogDefinition.getContents('Link').get('cmbTarget').items = options;
			}
		}

		// Advanced features
		var advanced = config.advanced || {};
		if(advanced){
			if(typeof advanced.enable != 'undefined' && !advanced.enable){
				dialogDefinition.removeContents('advanced');
			}
		}
	}

	if(dialogName == 'iframe'){
		var config = ckeditor_management.iframe || {};

		// Description
		var description = config.description || {};
		if(description){
			if(typeof description.name != 'undefined' && !description.name){
				dialogDefinition.getContents('info').remove('name');
			}
			if(typeof description.title != 'undefined' && !description.title){
				dialogDefinition.getContents('info').remove('title');
			}
			if(typeof description.description != 'undefined' && !description.description){
				dialogDefinition.getContents('info').remove('longdesc');
			}
		}

		// Layout
		var layout = config.layout || {};
		if(layout){
			if(typeof layout.scroll != 'undefined' && !layout.scroll){
				dialogDefinition.getContents('info').remove('scrolling');
			}
			if(typeof layout.border != 'undefined' && !layout.border){
				dialogDefinition.getContents('info').remove('frameborder');
			}
			if(typeof layout.align != 'undefined' && !layout.align){
				dialogDefinition.getContents('info').remove('align');
			}
		}

		// Advanced features
		var advanced = config.advanced || {};
		if(advanced){
			if(typeof advanced.enable != 'undefined' && !advanced.enable){
				dialogDefinition.removeContents('advanced');
			}
		}
	}

	if(dialogName == 'table' || dialogName == 'tableProperties'){
		var config = ckeditor_management.table || {};

		// Layout
		var layout = config.layout || {};
		if(layout){
			if(typeof layout.border != 'undefined' && !layout.border){
				dialogDefinition.getContents('info').remove('txtBorder');
			}
			if(typeof layout.align != 'undefined' && !layout.align){
				dialogDefinition.getContents('info').remove('cmbAlign');
			}
			if(typeof layout.width != 'undefined' && !layout.width){
				dialogDefinition.getContents('info').remove('txtWidth');
			}
			if(typeof layout.height != 'undefined' && !layout.height){
				dialogDefinition.getContents('info').remove('txtHeight');
			}
			if(typeof layout.cellspacing != 'undefined' && !layout.cellspacing){
				dialogDefinition.getContents('info').remove('txtCellSpace');
			}
			if(typeof layout.cellpadding != 'undefined' && !layout.cellpadding){
				dialogDefinition.getContents('info').remove('txtCellPad');
			}
		}

		// Layout
		var description = config.description || {};
		if(description){
			if(typeof description.caption != 'undefined' && !description.caption){
				dialogDefinition.getContents('info').remove('txtCaption');
			}
			if(typeof description.summary != 'undefined' && !description.summary){
				dialogDefinition.getContents('info').remove('txtSummary');
			}
		}

		// Advanced features
		var advanced = config.advanced || {};
		if(advanced){
			if(typeof advanced.enable != 'undefined' && !advanced.enable){
				dialogDefinition.removeContents('advanced');
			}
		}
	}

});
