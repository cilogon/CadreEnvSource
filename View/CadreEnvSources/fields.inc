<?php
  // Determine if fields are editable
  $e = false;
  
  if(($this->action == "add" && $permissions['add']) || ($this->action == "edit" && $permissions['edit']))
    $e = true;
    
  // We shouldn't get here if we don't have at least read permission, but check just in case
  
  if(!$e && !$permissions['view'])
    return false;
  
  // Add breadcrumbs
  print $this->element("coCrumb");

  $args = array();
  $args['plugin'] = null;
  $args['controller'] = 'org_identity_sources';
  $args['action'] = 'index';
  $args['co'] = $cur_co['Co']['id'];
  $this->Html->addCrumb(_txt('ct.org_identity_sources.pl'), $args);

  $args = array();
  $args['plugin'] = null;
  $args['controller'] = 'org_identity_sources';
  $args['action'] = 'edit';
  $args[] = $vv_oisid;
  $this->Html->addCrumb($cadre_env_sources[0]['OrgIdentitySource']['description'], $args);

  $crumbTxt = _txt('op.config');
  $this->Html->addCrumb($crumbTxt);
  
  print $this->Form->hidden('org_identity_source_id', array('default' => $vv_oisid)) . "\n";
?>
<ul id="<?php print $this->action; ?>_cadre_env_source" class="fields form-list form-list-admin">
  <li>
    <div class="field-name">
      <div class="field-title">
        <?php print _txt('pl.cadreenvsource.mode.dupe'); ?>
        <span class="required">*</span><br />
      </div>
    </div>
    <div class="field-info">
      <?php
        global $cm_lang, $cm_texts;
        $attrs = array();
        $attrs['value'] = (!empty($cadre_env_sources[0]['CadreEnvSource']['duplicate_mode']) ? $cadre_env_sources[0]['CadreEnvSource']['duplicate_mode'] : "");
        $attrs['empty'] = false;

        if($e) {
          print $this->Form->select('duplicate_mode',
                                    $cm_texts[ $cm_lang ]['pl.cadreenvsource.en.mode.dupe'],
                                    $attrs);

          if($this->Form->isFieldError('duplicate_mode')) {
            print $this->Form->error('duplicate_mode');
          }
        } else {
          print _txt('pl.cadreenvsource.en.mode.dupe', null, $cadre_env_sources[0]['CadreEnvSource']['duplicate_mode']);
        }
      ?>
    </div>
  </li>
  <li>
    <div class="field-name">
      <div class="field-title">
        <?php print ($e ? $this->Form->label('redirect_on_duplicate', _txt('pl.cadreenvsource.redirect.dupe')) : _txt('pl.cadreenvsource.redirect.dupe')); ?>
      </div>
    </div>
    <div class="field-info">
      <?php print ($e
                   ? $this->Form->input('redirect_on_duplicate', array('size' => 60))
                   : filter_var($cadre_env_sources[0]['CadreEnvSource']['redirect_on_duplicate'],FILTER_SANITIZE_SPECIAL_CHARS)); ?>
    </div>
  </li>
</ul>
<div id="env_attributes" class="field-children table-container">
  <table id="<?php print $this->action; ?>_cadre_env_attributes">
    <?php
      $l = 1;
    ?>
    <tbody>
      <tr>
        <th><?php print _txt('fd.attribute'); ?></th>
        <th><?php print _txt('fd.attr.env'); ?></th>
      </tr>
      <?php foreach($vv_available_attributes as $field => $attr): ?>
      <tr class="line<?php print ($l % 2); $l++; ?>">
        <td>
          <?php
            print $attr['label'];
            
            if(isset($attr['required']) && $attr['required']) {
              print "<span class=\"required\">*</span>";
            }
            
            if(!empty($attr['desc'])) {
              print "<br /><span class=\"descr\">" . $attr['desc'] . "</span>";
            }
          ?>
        </td>
        <td>
          <?php
            $args = array();
            $args['size'] = 40;
            
            if(!empty($attr['default'])) {
              $args['default'] = $attr['default'];
            }
            
            if(isset($attr['required']) && $attr['required']) {
              $args['required'] = true;
            }
            
            print $this->Form->input($field, $args);
            
            if(isset($attr['canLogin']) && $attr['canLogin']) {
              $args = array();
              $args['label'] = _txt('fd.identifier.login');
              
              print "<br />" . $this->Form->input($field.'_login', $args);
            }
          ?>
        </td>
      </tr>
      <?php endforeach; // $attrs ?>
      <tr>
        <td><span class="required"><?php print _txt('fd.req'); ?></span></td>
        <td><?php print $this->Form->submit($submit_label); ?></td>
      </tr>
    </tbody>
  </table>
</div>
