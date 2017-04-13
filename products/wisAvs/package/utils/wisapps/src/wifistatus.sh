#!/bin/ash

ap_addr=`ifconfig br-lan | grep "inet addr" | awk '{print $2}'`
echo $ap_addr
sta_addr=`ifconfig wlan0 | grep "inet addr" | awk '{print $2}'`

if [ "$sta_addr" != "" ]
then
	echo $sta_addr
	iwinfo wlan0 info >> /etc/config/sta_wifistatus
	ifconfig wlan0 | grep "inet addr" | awk '{print $2}' >> /etc/config/sta_wifistatus

	iwinfo wlan0-1 info >> /etc/config/ap_wifistatus
	ifconfig br-lan | grep "inet addr" | awk '{print $2}' >> /etc/config/ap_wifistatus

elif [ "$sta_addr" == "" ]
then
	iwinfo >> /etc/config/ap_wifistatus
	ifconfig br-lan | grep "inet addr" | awk '{print $2}' >> /etc/config/ap_wifistatus

fi


exit 0
