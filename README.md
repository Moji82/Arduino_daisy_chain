# Arduino_daisy_chain
This repository presents a daisy chain connection between PC and Arduinos. The first Arduino is connected to the PC via USB connection . The TX pin of the first Arduino is connected to the RX pin of the second Aruino. This connection can be extended to the third, forth and more Arduinos by connecting the TX pin to the RX pin of the next one.

To make the first Arduino blink, '1' is sent via the serial port. For making the second one blink '2' is sent, and finally for making the last one blink '3' is sent to the Daisy chain.
