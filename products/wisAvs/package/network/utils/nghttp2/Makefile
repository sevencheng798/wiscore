#
# Copyright (C) 2006-2015 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=nghttp2
PKG_VERSION:=1.9.2
PKG_RELEASE:=1
PKG_USE_MIPS16:=0

PKG_BUILD_PARALLEL:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://github.com/nghttp2/nghttp2/releases/download/v1.9.2/

PKG_MD5SUM:=38dd619b2e77cbac69b99f52a053d25a

PKG_LICENSE:=nghttp2
PKG_LICENSE_FILES:=LICENSE
PKG_INSTALL:=1
PKG_BUILD_DEPENDS = libopenssl

include $(INCLUDE_DIR)/package.mk

define Package/libnghttp2
  SECTION:=libs
  CATEGORY:=Libraries
  TITLE:=nghttp2 is an implementation of HTTP/2 client 
  URL:=http://www.nghttp2.org/
  DEPENDS:=+zlib +libopenssl +libxml2 +libevent2-openssl
endef
#TITLE+= (libraries)
#nghttp2 is an implementation of HTTP/2 client, server and proxy
  
define Package/libnghttp2/description
This package contains the libnghttp2 shared libraries, needed by other programs.
endef

TARGET_CFLAGS += $(FPIC)
CONFIGURE_ARGS += \


define Build/InstallDev
	$(INSTALL_DIR) $(1)/usr/include
	$(CP) $(PKG_INSTALL_DIR)/usr/include/nghttp2 $(1)/usr/include/
	$(INSTALL_DIR) $(1)/usr/lib/
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/libnghttp2.* $(1)/usr/lib/
	$(INSTALL_DIR) $(1)/usr/lib/pkgconfig
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/pkgconfig/libnghttp2.pc $(1)/usr/lib/pkgconfig/
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/nghttp* $(1)/usr/bin/
endef

define Package/libnghttp2/install
	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/libnghttp2.so.* $(1)/usr/lib/
endef

$(eval $(call BuildPackage,libnghttp2))
