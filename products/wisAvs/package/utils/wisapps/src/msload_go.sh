#!/bin/sh
#cd /usr/bin
# set pin for zl38062 reset pin
echo "36" > /sys/class/gpio/export
echo "out" > /sys/class/gpio/gpio36/direction
echo "1" > /sys/class/gpio/gpio36/value

MODULES="zl38067tw"
for module in $MODULES
do
	DRIVER=""$module".ko"
	RUN=`lsmod | grep $module`
	if [ "$RUN" == "" ]; then
		insmod $DRIVER
	fi
done

gpio_reset &

alexa_http -p 9999 > /dev/console 2>&1 &

alexa_run_demo > /dev/console 2>&1 &

cd /mnt
