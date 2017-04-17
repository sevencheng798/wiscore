# WisCore SDK
编译说明：
第一次编译需先设置产品属性，如果已经编译过SDK但要更改产品类型也需要重新设置产品属性
如果再次编译相同产品就无需在设置产品属性

第一次编译准备
1、下载sdk
git clone https://github.com/sevencheng798/wiscore

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

