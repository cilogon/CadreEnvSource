<?php
  
global $cm_lang, $cm_texts;

// When localizing, the number in format specifications (eg: %1$s) indicates the argument
// position as passed to _txt.  This can be used to process the arguments in
// a different order than they were passed.

$cm_cadre_env_source_texts['en_US'] = array(
  // Titles, per-controller
  'ct.cadre_env_sources.1'  => 'CADRE Env Organizational Identity Source',
  'ct.cadre_env_sources.pl' => 'CADRE Env Organizational Identity Sources',
  
  // Enumeration language texts
  'pl.cadreenvsource.en.mode.dupe' => array(
    CadreEnvSourceDuplicateModeEnum::SORIdentifier    => 'SOR Identifier Match',
    CadreEnvSourceDuplicateModeEnum::AnyIdentifier    => 'Any Identifier Match',
    CadreEnvSourceDuplicateModeEnum::LoginIdentifier  => 'Login Identifier Match',
  ),
  
  // Error messages
  'er.cadreenvsource.dupe'           => 'Identifier "%1$s" is already registered',
  'er.cadreenvsource.sorid'          => 'Identifier (SORID) variable "%1$s" not set',
  'er.cadreenvsource.sorid.cfg'      => 'Identifier (SORID) mapping not defined',
  'er.cadreenvsource.sorid.dupe'     => 'SORID "%1$s" is already associated with %2$s',
  'er.cadreenvsource.sorid.mismatch' => 'Requested ID does not match %1$s; CadreEnvSource does not support general retrieve operations',
  'er.cadreenvsource.token'          => 'Token error',
  
  // Plugin texts
  'pl.cadreenvsource.mode.dupe'               => 'Duplicate Handling Mode',
  'pl.cadreenvsource.name.unknown'            => 'Unknownname',
  'pl.cadreenvsource.redirect.dupe'           => 'Redirect on Duplicate',
  'pl.cadreenvsource.sorid.desc'              => 'This must be set to an environment variable holding a unique identifier for any authenticated user.',
  'pl.cadreenvsource.affiliation_scoped.desc' => 'Scoped Affiliation'
);
