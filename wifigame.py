import network, time
def Handygen(ssid, wifipassword):
    while True:
        sta_if = network.WLAN(network.STA_IF)
        sta_if.active(True)
        sta_if.connect(ssid, wifipassword)
        time.sleep(3)
        sta_if.active(False)
        time.sleep(5)
    
def Createnet(ssid, wifipassword):
    ap = network.WLAN(network.AP_IF)
    ap.active(True)
    ap.config(essid=ssid, password=wifipassword)
    
def Stopnet():
    ap = network.WLAN(network.AP_IF)
    ap.active(False)
