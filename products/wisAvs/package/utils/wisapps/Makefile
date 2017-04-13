#seven
include $(TOPDIR)/rules.mk
#include $(INCLUDE_DIR)/kernel.mk

PKG_NAME:= wisapps
PKG_RELEASE:=1
PKG_VERSION:=1.0

include $(INCLUDE_DIR)/package.mk
#PKG_BUILD_DIR:= $(BUILD_DIR)/$(PKG_NAME)

define Package/wisapps
	SECTION:=utils
	CATEGORY:=Utilities
	TITLE:=Hive apps and utils
	DEPENDS:=+kmod-iio-core +libiio +libao +alsa-lib +libcurl +libuci
endef

define Package/wisapps/description
	hive apps building test
endef

define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)/src
	$(CP) ./src/* $(PKG_BUILD_DIR)/src/
	$(CP) ./include $(PKG_BUILD_DIR)/
	$(CP) ./lib $(PKG_BUILD_DIR)/
endef

define Build/Compile
	$(MAKE) -C $(PKG_BUILD_DIR)/src \
	$(TARGET_CONFIGURE_OPTS) CFLAGS="$(TARGET_CFLAGS)"
endef

	#$(TARGET_CONFIGURE_OPTS) CFLAGS="$(TARGET_CFLAGS) -I$(LINUX_DIR)/include"
define Package/wisapps/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_DIR) $(1)/usr/lib
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/src/msload_go.sh $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/src/16kk.raw $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/src/alexa_run_demo $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/src/tw_38067_access $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/src/alexa_http $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/src/wifistatus.sh $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/src/gpio_reset $(1)/usr/bin

	$(INSTALL_DIR) $(1)/lib/modules/3.18.45
	$(CP) $(PKG_BUILD_DIR)/src/*.ko $(1)/lib/modules/3.18.45
	$(CP) $(PKG_BUILD_DIR)/src/lib/* $(1)/usr/lib
	$(CP) $(PKG_BUILD_DIR)/lib/libcJSON.so $(1)/usr/lib
	$(CP) $(PKG_BUILD_DIR)/lib/libzl380tw.so $(1)/usr/lib
	$(CP) $(PKG_BUILD_DIR)/lib/fdk/lib* $(1)/usr/lib
	$(CP) $(PKG_BUILD_DIR)/src/sound $(1)/usr/lib

	$(INSTALL_DIR) $(1)/etc
	$(CP) $(PKG_BUILD_DIR)/src/wisalexainfo $(1)/etc

endef
	#$(INSTALL_BIN) $(PKG_BUILD_DIR)/src/16k.pcm $(1)/usr/bin
	#$(INSTALL_BIN) $(PKG_BUILD_DIR)/src/48k.pcm $(1)/usr/bin

$(eval $(call BuildPackage,wisapps))

