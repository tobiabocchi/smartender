# smartender

I built a "smart bartender" using an Arduino nano, some wood and simple electrical componets.

![alt text][smartender]

[smartender]: https://raw.githubusercontent.com/tobiabocchi/smartender/master/pictures/smartender-front.jpg?token=AG5J6HZ2M427LXPL2UK64DK42SMWU

## 1. The Remote

Right now the bartender is controlled by a wired remote, which is connected to the wooden box using an ethernet cable.
Inside the remote there is an 
[arduino nano clone](https://www.amazon.com/ELEGOO-Arduino-ATmega328P-Without-Compatible/dp/B0713XK923)
which allows me to control each pump and order cocktails. The code you see in the smartender.ino file is loaded on the remote's arduino.

![alt text][remote]

[remote]: https://raw.githubusercontent.com/tobiabocchi/smartender/master/pictures/smartender-remote.jpg?token=AG5J6HZ2EKLDTVXGRT67YCC42SM36

## 2. The Inside

There is a total of 6 pumps inside the wooden box, each one of them can be connected to one of the bottle on the sides, for a total of 6 different beverages to make cocktails with.
The pumps work with AC current and they need to be plugged in directly into a powersocket without any transformer, that is why inside the wooden box there are multiple power sockets as you can see in the picture below, the simple plug is for the pumps, the transformer for the lights, which are hidden in the lower compartment below the glass. On the side there is an 
[8 channel relay module](https://www.amazon.com/ELEGOO-Channel-Optocoupler-Arduino-Raspberry/dp/B01HCFJC0Y/ref=sr_1_9?keywords=arduino+relay&qid=1557438631&s=gateway&sr=8-9)
that gets power from the socket and feeds it to the correct pump on arduino's notice. As I have mentioned above the remote connects through an ethernet chord which plugs into the hole on the left where all the relays' cables go.

![alt text][smartender-inside]

[smartender-inside]:https://raw.githubusercontent.com/tobiabocchi/smartender/master/pictures/smartender-inside.jpg?token=AG5J6HZ4QWUFZ57BGDO7S5242SN5I

## 3. Main build challenges

One of the trickiest part was to figure out how to get the liquid from the bottle to the glass. I wanted to keep all the bottles upside-down so I built two extra wooden structure to hold them in place and then bough some 
[metal pour spouts](https://www.amazon.com/12-Metal-Liquor-Pour-Spouts/dp/B008ZDH69C)
to attach them to the tubes. I opted for a kind of complicated path from the bottle to the glass but I think in the end it came out very good looking, the tubes from the bottles come in from the back of the box, they go into the pumps and then they come out of the front's bottom, they wrap around the cube to go on the sides, then back into the cube again and straight up (which is the coolest part because when it's running you can actually see the liquid going through these parallel tubes which seem suspended in mid-air and your glass is right between them) at last they come out of the cube's roof and loop back into it. I also added some small metal supports to the end of the tubes to make them pour nicely.

![alt text][smartender-pumps]

[smartender-pumps]:https://raw.githubusercontent.com/tobiabocchi/smartender/master/pictures/smartender-pumps.jpg?token=AG5J6HYRF7ZWCSCDQYQJXP242SQ2I

Another big issue was that the metal pour attached to the bottles with the tube on were leaking, so I mounted a one way valve to block the thinner tube of the metal pour and put some glue around its base, this is how they look after the modification:

![alt text][metal-pour-mod]

[metal-pour-mod]:https://raw.githubusercontent.com/tobiabocchi/smartender/master/pictures/metal-pour-modified.jpg?token=AG5J6H6F5TFITNVHOZYMTIS42SPWQ

## Future updates
[] Wireless remote
[] Optimize code
[] Maybe switch to a raspberry?
