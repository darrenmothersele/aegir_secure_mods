<?php

function securemods_provision_services() {
	return array('securemods' => NULL);
}

class provisionService_securemods extends provisionService {
	public $service = 'securemods';
	static function subscribe_site($context) {
		$context->setProperty('aegir_secure_mods');
	}
}

function securemods_provision_apache_vhost_config($uri, $data) {
	$config = <<<EOD
	<IfModule mod_rewrite.c>
	  RewriteEngine on
	  RewriteRule ^/update.php / [L,R=404]   
	  RewriteRule ^/install.php / [L,R=404]  
	  RewriteRule ^/CHANGELOG.txt / [L,R=404]
	  RewriteRule ^/COPYRIGHT.txt / [L,R=404]
	  RewriteRule ^/INSTALL.mysql.txt / [L,R=404]
	  RewriteRule ^/INSTALL.pgsql.txt / [L,R=404]
	  RewriteRule ^/INSTALL.sqlite.txt / [L,R=404]
	  RewriteRule ^/INSTALL.txt / [L,R=404]
	  RewriteRule ^/LICENSE.txt / [L,R=404]
	  RewriteRule ^/MAINTAINERS.txt / [L,R=404] 
	  RewriteRule ^/README.txt / [L,R=404]  
	  RewriteRule ^/UPGRADE.txt / [L,R=404]   
	  RewriteRule ^/authorize.php / [L,R=404]
	  RewriteRule ^/cron.php / [L,R=404]
	  RewriteRule ^/web.config / [L,R=404]
	  RewriteRule ^/xmlrpc.php / [L,R=404]
	</IfModule>
EOD;
  if (d()->aegir_secure_mods) {
    return $config;
  }
}
