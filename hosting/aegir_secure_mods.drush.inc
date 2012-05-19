<?php

function aegir_secure_mods_hosting_site_context_options(&$task) {
  if (isset($task->ref->aegir_secure_mods_block_install_files) && !empty($task->ref->aegir_secure_mods_block_install_files)) {
    $task->context_options['aegir_secure_mods'] = $task->ref->aegir_secure_mods_block_install_files;
  } else {
    $task->context_options['aegir_secure_mods'] = FALSE;
  }
}

function aegir_secure_mods_drush_context_import($context, &$node) {
  if ($context->type == 'site') {
    if (isset($context->aegir_secure_mods) && !empty($context->aegir_secure_mods)) {
      $node->aegir_secure_mods_block_install_files = $context->aegir_secure_mods;
    }
  }
}
