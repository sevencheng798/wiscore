# WisCore SDK
This SDK is for WisCore hardware development platform base on OpenWrt system. Software features include three product features: WisAp, WisAvs(Amazon Alexa Avs function), WisGw(wiscore gateway)

Compiler introduction:
If you are the first compiler SDK you need to choose to use the product type and then set the compiler environment. so that the next time you recompile the same types of products when there is no need to in the environmental settings unless you want to switch to other types of products

##For compiler WisAp:
### Required Hardware
Before you get started, let's review what you'll need.
1.WisCore development board 
2.Micro-USB power cable
3.Internet connection - Ethernet for download firmware to wiscore board

第一次编译准备
1、下载sdk
git clone https://github.com/sevencheng798/wiscore
详细步骤请阅读
https://github.com/sevencheng798/get_started_with_wiscore

2、下载dl package
如果产品为wisAp或者wis hgw可以下载dl：
svn co http://192.168.1.202:8088/svn/rak/hive/wisap/dl
cp dl/* <$SDK_DIR>/wiswrt/rak/dl

如果产品选择wisAvs或者wisAlexa需下载dl-rc2：
svn co http://192.168.1.202:8088/svn/rak/hive/wisap/dl-rc2
cp dl-rc2/* <$SDK_DIR>/wiswrt/rak/dl


3、选择产品类型, 即在编译之前需确定产品类型，如下做选择：
./build/envsetup.sh <product> <type> <option>	//wisAp为一类产品， wisAvs为一类产品， wisGW为一类产品

如编译wisAp产品，可以执行：
./build/envsetup.sh wisAp hgw
如清除SDK恢复初始状态：
./build/envsetup.sh wisAp hgw clean

开始执行编译SDK
4、make

5、产出的镜像在out/target/bin目录下

如果已经编译过了wisAp产品，又想编译wisAvs产品需重新执行选择产品类型，再一次编译才可

