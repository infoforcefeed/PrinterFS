# PrinterFS

Distributed filesystem.

## Goals

* Spread non-replicated files over many, small-disk, cheap boxes
* Files should be owned by a single node, so contention should be **less** of a
  problem
* Simple to configure, setup, keep running. As few bells and whistles as
  possible.
* DHT
* As safe as possible, make trade-offs for safety over latency when the question
  arises.

## Nice-to-haves

* In-memory LRÜ cache for files and metadata on every node. Should be configurable.
* Simple rehashing/auto-discovery. If a new node comes online, make sure files
  that are now in it's keyspace are moved to it from the nodes previous.
* Compression for over-the-wire transfers (LZ4 is pretty easy)

# Üsage

## Installation

Make sure you have your kernel headers available. On Übuntu, you can do:

```
sudo apt-get install linux-headers-$(uname -r)
```

Then you should just be able to:

```
make
sudo insmod PrinterFS.ko
```

## Üninstallation

```
sudo rmmod PrinterFS
```

## THE STORY

THE TRÜE STORY BEHIND PRINTERFS

SON: "DAD, WHAT IS SPACE?"

DAD: "SON, PRINTERFS IS SPACE. IT IS ALL OF THE SPACE AT THE CLOÜD OF THE 
SCALING VECTOR."

SON: "BÜT DAYD WHYFOR NOT HAVE FOOT FOR EATING!"

DAD: "COMMÜNIST CONÜTRY IS DIFFERENT. FEAR NOT SON FOR WE WILL REJOICE OFF THE 
YOKE OF CAPITALIST PIGDOGZ ENSLAVIN ÜS"

SON: "OH ISEE, FATHER JNERÜLA WILL SAVEÜS FROM THE PRINTER AND GIVE ÜS FREE AND 
CLOÜD AND HAPPY NOW?"

DAD: "THAT'S RIGHT COMRADE! JOIN FOR TO ÜS CONQÜEROR THE WORLDS! HE WHO WAITS 
BEHIND THE WALL ZALGO HE IS COMEING HELP FOR OÜR HOME AND GLODY AND SAFETYNESS"
