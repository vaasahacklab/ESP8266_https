# ESP8266_https
HTTPS request example on ESP8266 witty board 

Add your WiFi credentials and server url into conf.h file.

To generate https fingerprint, use the following command:

openssl s_client -connect example.com:443

Copy everything in between -----BEGIN CERTIFICATE----- and -----END CERTIFICATE-----
and paste it in a new file named cert.perm

Then use following command to generate fingerprint:

openssl x509 -noout -in ./cert.perm -fingerprint -sha1

https://vaasa.hacklab.fi