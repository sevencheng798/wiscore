#
# Copyright (C) 2006 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=libao
PKG_VERSION:=1.2.0-rak
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://github.com/sevencheng798/libao-1.2.0-rak
PKG_SOURCE_PROTO:=git
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_VERSION:=68e5e860f80d6dc8a7747cd8af40ddf7d1584257

PKG_FIXUP:=autoreconf
PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/libao
  SECTION:=libs
  DEPENDS:=+alsa-lib
  CATEGORY:=Libraries
  TITLE:=A cross platform audio library
  URL:=http://www.xiph.org/ao/
endef

define Package/libao/description
	Libao is a cross-platform audio library that allows programs to
	output audio using a simple API on a wide variety of platforms.
endef
#	--enable-static
CONFIGURE_ARGS += \
	--enable-shared \
	--disable-esd \
	--disable-arts \
	--disable-nas \
	--disable-pulse \
	--disable-broken-oss \
	--enable-alsa-mmap

TARGET_CFLAGS += $(FPIC)

define Build/InstallDev
	$(INSTALL_DIR) $(1)/usr/include
	$(CP) $(PKG_INSTALL_DIR)/usr/include/ao $(1)/usr/include/
	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/libao.so* $(1)/usr/lib/
	$(INSTALL_DIR) $(1)/usr/lib/pkgconfig
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/pkgconfig/ao.pc $(1)/usr/lib/pkgconfig/
endef

define Package/libao/install
	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/libao.so.* $(1)/usr/lib/
	$(INSTALL_DIR) $(1)/usr/lib/ao/plugins-4
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/ao/plugins-4/lib*.so $(1)/usr/lib/ao/plugins-4/
endef

$(eval $(call BuildPackage,libao))
