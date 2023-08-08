<?php

App::uses("SOISController", "Controller");

class CadreEnvSourcesController extends SOISController {
  // Class name, used by Cake
  public $name = "CadreEnvSources";
  
  // Establish pagination parameters for HTML views
  public $paginate = array(
    'limit' => 25,
    'order' => array(
      // We don't really need pagination...
      'env_name_given' => 'asc'
    )
  );
  
  /**
   * Callback before views are rendered.
   *
   * @since  COmanage Registry v3.1.0
   */
  
  public function beforeRender() {
    $this->set('vv_available_attributes', $this->CadreEnvSource->availableAttributes());
    
    parent::beforeRender();
  }
  
  /**
   * Authorization for this Controller, called by Auth component
   * - precondition: Session.Auth holds data used for authz decisions
   * - postcondition: $permissions set with calculated permissions
   *
   * @since  COmanage Registry v0.8
   * @return Array Permissions
   */
  
  function isAuthorized() {
    $roles = $this->Role->calculateCMRoles();
    
    // Construct the permission set for this user, which will also be passed to the view.
    $p = array();
    
    // Determine what operations this user can perform
    
    $coadmin = false;
    
    if($roles['coadmin'] && !$this->CmpEnrollmentConfiguration->orgIdentitiesPooled()) {
      // CO Admins can only manage org identity sources if org identities are NOT pooled
      $coadmin = true;
    }
    
    // Delete an existing CO Provisioning Target?
    $p['delete'] = $roles['cmadmin'] || $coadmin;
    
    // Edit an existing CO Provisioning Target?
    $p['edit'] = $roles['cmadmin'] || $coadmin;
    
    // View all existing CO Provisioning Targets?
    $p['index'] = $roles['cmadmin'] || $coadmin;
    
    // View an existing CO Provisioning Target?
    $p['view'] = $roles['cmadmin'] || $coadmin;
    
    $this->set('permissions', $p);
    return($p[$this->action]);
  }
}
