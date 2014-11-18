<?php

function _ckeditor_management_features_form($form, $form_state){
	$defaults = variable_get('ckeditor_management_features', array());

	$form['ckeditor_management_features']['#tree'] = true;

	$form['ckeditor_management_features']['link'] = array(
		'#type' => 'fieldset',
		'#title' => t('Link'),
		'#collapsible' => true,
		'#collapsed' => true,

		// Anchor links
		'anchor' => array(
			'#type' => 'fieldset',
			'#title' => t('Anchor'),
			'#collapsible' => false,
			'#collapsed' => false,

			'enable' => array(
				'#title' => t('Allow anchor links'),
				'#type' => 'checkbox',
				'#return_value' => true,
				'#default_value' => isset($defaults['link']) && isset($defaults['link']['anchor']) && isset($defaults['link']['anchor']['enable']) ? $defaults['link']['anchor']['enable'] : true,
			),
			'name' => array(
				'#title' => t('Anchor by target name'),
				'#type' => 'checkbox',
				'#return_value' => true,
				'#default_value' => isset($defaults['link']) && isset($defaults['link']['anchor']) && isset($defaults['link']['anchor']['name']) ? $defaults['link']['anchor']['name'] : true,
				'#states' => array(
					'visible' => array(
						':input[name="ckeditor_management_features[link][anchor][enable]"]' => array(
							'checked' => true
						)
					)
				)
			),
			'id' => array(
				'#title' => t('Anchor by target id'),
				'#type' => 'checkbox',
				'#return_value' => true,
				'#default_value' => isset($defaults['link']) && isset($defaults['link']['anchor']) && isset($defaults['link']['anchor']['id']) ? $defaults['link']['anchor']['id'] : true,
				'#states' => array(
					'visible' => array(
						':input[name="ckeditor_management_features[link][anchor][enable]"]' => array(
							'checked' => true
						)
					)
				)
			),
		),

		// Target
		'target' => array(
			'#type' => 'fieldset',
			'#title' => t('Target'),
			'#collapsible' => false,
			'#collapsed' => false,

			'enable' => array(
				'#title' => t('Allow define target'),
				'#type' => 'checkbox',
				'#return_value' => true,
				'#default_value' => isset($defaults['link']) && isset($defaults['link']['target']) && isset($defaults['link']['target']['enable']) ? $defaults['link']['target']['enable'] : true,
			),
			'options' => array(
				'#title' => t('Target options'),
				'#type' => 'checkboxes',
				'#options' => array(
					'frame' => t('Frame'),
					'popup' => t('Popup'),
					'_blank' => t('New window'),
					'_top' => t('Main window'),
					'_self' => t('Same window'),
					'_parent' => t('Parent window'),
				),
				'#default_value' => isset($defaults['link']) && isset($defaults['link']['target']) && isset($defaults['link']['target']['options']) ? $defaults['link']['target']['options'] : array(
					'frame' => 'frame',
					'popup' => 'popup',
					'_blank' => '_blank',
					'_top' => '_top',
					'_self' => '_self',
					'_parent' => '_parent',
				),
				'#states' => array(
					'visible' => array(
						':input[name="ckeditor_management_features[link][target][enable]"]' => array(
							'checked' => true
						)
					)
				)
			)
		),

		// Advanced
		'advanced' => array(
			'#type' => 'fieldset',
			'#title' => t('Advanced'),
			'#collapsible' => false,
			'#collapsed' => false,

			'enable' => array(
				'#title' => t('Allow define advanced features'),
				'#type' => 'checkbox',
				'#return_value' => true,
				'#default_value' => isset($defaults['link']) && isset($defaults['link']['advanced']) && isset($defaults['link']['advanced']['enable']) ? $defaults['link']['advanced']['enable'] : true,
			),
		)
	);

	$form['ckeditor_management_features']['image'] = array(
		'#type' => 'fieldset',
		'#title' => t('Image'),
		'#collapsible' => true,
		'#collapsed' => true,

		// Size
		'size' => array(
			'#type' => 'fieldset',
			'#title' => t('Size'),
			'#collapsible' => false,
			'#collapsed' => false,

			'enable' => array(
				'#title' => t('Allow modify image size'),
				'#type' => 'checkbox',
				'#return_value' => true,
				'#default_value' => isset($defaults['image']) && isset($defaults['image']['size']) && isset($defaults['image']['size']['enable']) ? $defaults['image']['size']['enable'] : true,
			),
			'width' => array(
				'#title' => t('Width'),
				'#type' => 'checkbox',
				'#return_value' => true,
				'#default_value' => isset($defaults['image']) && isset($defaults['image']['size']) && isset($defaults['image']['size']['width']) ? $defaults['image']['size']['width'] : true,
				'#states' => array(
					'visible' => array(
						':input[name="ckeditor_management_features[image][size][enable]"]' => array(
							'checked' => true
						)
					)
				)
			),
			'height' => array(
				'#title' => t('Height'),
				'#type' => 'checkbox',
				'#return_value' => true,
				'#default_value' => isset($defaults['image']) && isset($defaults['image']['size']) && isset($defaults['image']['size']['height']) ? $defaults['image']['size']['height'] : true,
				'#states' => array(
					'visible' => array(
						':input[name="ckeditor_management_features[image][size][enable]"]' => array(
							'checked' => true
						)
					)
				)
			),
		),

		// Border
		'border' => array(
			'#type' => 'fieldset',
			'#title' => t('Border'),
			'#collapsible' => false,
			'#collapsed' => false,

			'enable' => array(
				'#title' => t('Allow modify image border'),
				'#type' => 'checkbox',
				'#return_value' => true,
				'#default_value' => isset($defaults['image']) && isset($defaults['image']['border']) && isset($defaults['image']['border']['enable']) ? $defaults['image']['border']['enable'] : true,
			),
		),

		// Margin
		'margin' => array(
			'#type' => 'fieldset',
			'#title' => t('Margin'),
			'#collapsible' => false,
			'#collapsed' => false,

			'enable' => array(
				'#title' => t('Allow modify image margin'),
				'#type' => 'checkbox',
				'#return_value' => true,
				'#default_value' => isset($defaults['image']) && isset($defaults['image']['margin']) && isset($defaults['image']['margin']['enable']) ? $defaults['image']['margin']['enable'] : true,
			),
			'horizontal' => array(
				'#title' => t('Horizontal margin'),
				'#type' => 'checkbox',
				'#return_value' => true,
				'#default_value' => isset($defaults['image']) && isset($defaults['image']['margin']) && isset($defaults['image']['margin']['horizontal']) ? $defaults['image']['margin']['horizontal'] : true,
				'#states' => array(
					'visible' => array(
						':input[name="ckeditor_management_features[image][margin][enable]"]' => array(
							'checked' => true
						)
					)
				)
			),
			'vertical' => array(
				'#title' => t('Vertical'),
				'#type' => 'checkbox',
				'#return_value' => true,
				'#default_value' => isset($defaults['image']) && isset($defaults['image']['margin']) && isset($defaults['image']['margin']['vertical']) ? $defaults['image']['margin']['vertical'] : true,
				'#states' => array(
					'visible' => array(
						':input[name="ckeditor_management_features[image][margin][enable]"]' => array(
							'checked' => true
						)
					)
				)
			),
		),

		// Link
		'link' => array(
			'#type' => 'fieldset',
			'#title' => t('Link'),
			'#collapsible' => false,
			'#collapsed' => false,

			'enable' => array(
				'#title' => t('Allow link in image'),
				'#type' => 'checkbox',
				'#return_value' => true,
				'#default_value' => isset($defaults['image']) && isset($defaults['image']['link']) && isset($defaults['image']['link']['enable']) ? $defaults['image']['link']['enable'] : true,
			),
			'options' => array(
				'#title' => t('Target options'),
				'#type' => 'checkboxes',
				'#options' => array(
					'_blank' => t('New window'),
					'_top' => t('Main window'),
					'_self' => t('Same window'),
					'_parent' => t('Parent window'),
				),
				'#default_value' => isset($defaults['image']) && isset($defaults['image']['link']) && isset($defaults['image']['link']['options']) ? $defaults['image']['link']['options'] : array(
					'_blank' => '_blank',
					'_top' => '_top',
					'_self' => '_self',
					'_parent' => '_parent',
				),
				'#states' => array(
					'visible' => array(
						':input[name="ckeditor_management_features[image][link][enable]"]' => array(
							'checked' => true
						)
					)
				)
			)
		),

		// Advanced
		'advanced' => array(
			'#type' => 'fieldset',
			'#title' => t('Advanced'),
			'#collapsible' => false,
			'#collapsed' => false,

			'enable' => array(
				'#title' => t('Allow define advanced features'),
				'#type' => 'checkbox',
				'#return_value' => true,
				'#default_value' => isset($defaults['image']) && isset($defaults['image']['advanced']) && isset($defaults['image']['advanced']['enable']) ? $defaults['image']['advanced']['enable'] : true,
			),
		)
	);

	$form['ckeditor_management_features']['iframe'] = array(
		'#type' => 'fieldset',
		'#title' => t('Iframe'),
		'#collapsible' => true,
		'#collapsed' => true,

		// Layout
		'layout' => array(
			'#type' => 'fieldset',
			'#title' => t('Layout'),
			'#collapsible' => false,
			'#collapsed' => false,

			'width' => array(
				'#title' => t('Width'),
				'#type' => 'checkbox',
				'#return_value' => true,
				'#default_value' => isset($defaults['iframe']) && isset($defaults['iframe']['layout']) && isset($defaults['iframe']['layout']['width']) ? $defaults['iframe']['layout']['width'] : true,
			),
			'height' => array(
				'#title' => t('Height'),
				'#type' => 'checkbox',
				'#return_value' => true,
				'#default_value' => isset($defaults['iframe']) && isset($defaults['iframe']['layout']) && isset($defaults['iframe']['layout']['height']) ? $defaults['iframe']['layout']['height'] : true,
			),
			'align' => array(
				'#title' => t('Align'),
				'#type' => 'checkbox',
				'#return_value' => true,
				'#default_value' => isset($defaults['iframe']) && isset($defaults['iframe']['layout']) && isset($defaults['iframe']['layout']['align']) ? $defaults['iframe']['layout']['align'] : true,
			),
			'scroll' => array(
				'#title' => t('Scroll options'),
				'#type' => 'checkbox',
				'#return_value' => true,
				'#default_value' => isset($defaults['iframe']) && isset($defaults['iframe']['layout']) && isset($defaults['iframe']['layout']['scroll']) ? $defaults['iframe']['layout']['scroll'] : true,
			),
			'border' => array(
				'#title' => t('Border options'),
				'#type' => 'checkbox',
				'#return_value' => true,
				'#default_value' => isset($defaults['iframe']) && isset($defaults['iframe']['layout']) && isset($defaults['iframe']['layout']['border']) ? $defaults['iframe']['layout']['border'] : true,
			),
		),

		// Description
		'description' => array(
			'#type' => 'fieldset',
			'#title' => t('Description'),
			'#collapsible' => false,
			'#collapsed' => false,

			'name' => array(
				'#title' => t('Name'),
				'#type' => 'checkbox',
				'#return_value' => true,
				'#default_value' => isset($defaults['iframe']) && isset($defaults['iframe']['description']) && isset($defaults['iframe']['description']['name']) ? $defaults['iframe']['description']['name'] : true,
			),
			'title' => array(
				'#title' => t('Title'),
				'#type' => 'checkbox',
				'#return_value' => true,
				'#default_value' => isset($defaults['iframe']) && isset($defaults['iframe']['description']) && isset($defaults['iframe']['description']['title']) ? $defaults['iframe']['description']['title'] : true,
			),
			'description' => array(
				'#title' => t('Description'),
				'#type' => 'checkbox',
				'#return_value' => true,
				'#default_value' => isset($defaults['iframe']) && isset($defaults['iframe']['description']) && isset($defaults['iframe']['description']['description']) ? $defaults['iframe']['description']['description'] : true,
			),
		),

		// Advanced
		'advanced' => array(
			'#type' => 'fieldset',
			'#title' => t('Advanced'),
			'#collapsible' => false,
			'#collapsed' => false,

			'enable' => array(
				'#title' => t('Allow define advanced features'),
				'#type' => 'checkbox',
				'#return_value' => true,
				'#default_value' => isset($defaults['iframe']) && isset($defaults['iframe']['advanced']) && isset($defaults['iframe']['advanced']['enable']) ? $defaults['iframe']['advanced']['enable'] : true,
			),
		)
	);

	$form['ckeditor_management_features']['table'] = array(
		'#type' => 'fieldset',
		'#title' => t('Table'),
		'#collapsible' => true,
		'#collapsed' => true,

		// Layout
		'layout' => array(
			'#type' => 'fieldset',
			'#title' => t('Layout'),
			'#collapsible' => false,
			'#collapsed' => false,

			'width' => array(
				'#title' => t('Width'),
				'#type' => 'checkbox',
				'#return_value' => true,
				'#default_value' => isset($defaults['table']) && isset($defaults['table']['layout']) && isset($defaults['table']['layout']['width']) ? $defaults['table']['layout']['width'] : true,
			),
			'height' => array(
				'#title' => t('Height'),
				'#type' => 'checkbox',
				'#return_value' => true,
				'#default_value' => isset($defaults['table']) && isset($defaults['table']['layout']) && isset($defaults['table']['layout']['height']) ? $defaults['table']['layout']['height'] : true,
			),
			'align' => array(
				'#title' => t('Align'),
				'#type' => 'checkbox',
				'#return_value' => true,
				'#default_value' => isset($defaults['table']) && isset($defaults['table']['layout']) && isset($defaults['table']['layout']['align']) ? $defaults['table']['layout']['align'] : true,
			),
			'border' => array(
				'#title' => t('Border options'),
				'#type' => 'checkbox',
				'#return_value' => true,
				'#default_value' => isset($defaults['table']) && isset($defaults['table']['layout']) && isset($defaults['table']['layout']['border']) ? $defaults['table']['layout']['border'] : true,
			),
			'cellspacing' => array(
				'#title' => t('Cell spacing'),
				'#type' => 'checkbox',
				'#return_value' => true,
				'#default_value' => isset($defaults['table']) && isset($defaults['table']['layout']) && isset($defaults['table']['layout']['cellspacing']) ? $defaults['table']['layout']['cellspacing'] : true,
			),
			'cellpadding' => array(
				'#title' => t('Cell padding'),
				'#type' => 'checkbox',
				'#return_value' => true,
				'#default_value' => isset($defaults['table']) && isset($defaults['table']['layout']) && isset($defaults['table']['layout']['cellpadding']) ? $defaults['table']['layout']['cellpadding'] : true,
			),
		),

		// Description
		'description' => array(
			'#type' => 'fieldset',
			'#title' => t('Description'),
			'#collapsible' => false,
			'#collapsed' => false,

			'caption' => array(
				'#title' => t('Caption'),
				'#type' => 'checkbox',
				'#return_value' => true,
				'#default_value' => isset($defaults['table']) && isset($defaults['table']['description']) && isset($defaults['table']['description']['caption']) ? $defaults['table']['description']['caption'] : true,
			),
			'summary' => array(
				'#title' => t('Summary'),
				'#type' => 'checkbox',
				'#return_value' => true,
				'#default_value' => isset($defaults['table']) && isset($defaults['table']['description']) && isset($defaults['table']['description']['summary']) ? $defaults['table']['description']['summary'] : true,
			),
		),

		// Advanced
		'advanced' => array(
			'#type' => 'fieldset',
			'#title' => t('Advanced'),
			'#collapsible' => false,
			'#collapsed' => false,

			'enable' => array(
				'#title' => t('Allow define advanced features'),
				'#type' => 'checkbox',
				'#return_value' => true,
				'#default_value' => isset($defaults['table']) && isset($defaults['table']['advanced']) && isset($defaults['table']['advanced']['enable']) ? $defaults['table']['advanced']['enable'] : true,
			),
		)
	);

	return system_settings_form($form);
}