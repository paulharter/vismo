# vismo/a

Webcam application to be used with bismo/a. This is a simple OpenFrameworks application.

## Build

First you will need to install xcode and its command line tools:

http://openframeworks.cc/setup/xcode/

Then install OpenFrameworks iteslf

http://openframeworks.cc/download/

Openframeworks has a folder structure to make building apps easier. One installed clone this repo in the myApps folder. Then you have to install a bunch of "addons", this involves cloning the repo of each into the addons folder. You will need:

- ofxCv
- ofxFaceTracker
- ofxGui
- ofxHTTP
- ofxIO
- ofxMediaType
- ofxNetworkUtils
- ofxOpenCv
- ofxSSLManager
- ofxTaskQueue


## Use

As currently configured the app sends head position information twice a second to pubnub, which is a SaaS data publishing service:


https://www.pubnub.com/

you can read this data stream using the subscribe key:

sub-c-feaea18a-4ce2-11e6-9236-02ee2ddab7fe

There is a pubnub auduino library to make reading it easy

https://www.pubnub.com/blog/2014-06-25-connect-arduino-to-pubnub-in-2-steps/


## Modify

You can add or change which data to send quite easily, it is coming from the `tracker` in lines 19-23. At the moment it's' just sending the orientation.


## Binary

You can downlaod a built binary that I have tested on OSX 10.11.6 here:

https://www.dropbox.com/sh/6ido3gb7hv7pxxk/AACXIDqu4iDs2xyjOErVsw8qa?dl=0

call me if you have any problems. Have fun.

Paul

