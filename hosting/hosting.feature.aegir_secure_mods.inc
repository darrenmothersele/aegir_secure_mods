<?php

function aegir_secure_mods_hosting_feature() {
  $features['aegir_secure_mods'] = array(
    'title' => t('Aegir Secure Mods'),
    'description' => t('Apply some configuration tweaks to harden up security.'),
    'status' => HOSTING_FEATURE_DISABLED,
    'module' => 'aegir_secure_mods',
    'group' => 'experimental',
  );
  return $features;
}
