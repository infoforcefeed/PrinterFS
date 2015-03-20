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

* In-memory LRU cache for files and metadata on every node. Should be configurable.
* Simple rehashing/auto-discovery. If a new node comes online, make sure files
  that are now in it's keyspace are moved to it from the nodes previous.
* Compression for over-the-wire transfers (LZ4 is pretty easy)

# Usage

## Installation

Make sure you have your kernel headers available. On Ubuntu, you can do:

```
sudo apt-get install linux-headers-$(uname -r)
```

Then you should just be able to:

```
make
sudo insmod PrinterFS.ko
```

## Uninstallation

```
sudo rmmod PrinterFS
```

## The Story

The true story behind PrinterFS

Son: "dad, what is space?"

Dad: "son, printerfs is space. it is all of the space at the cloud of the 
scaling vector."

Son: "but dayd whyfor not have foot for eating!"

Dad: "communist conutry is different. fear not son for we will rejoice off the 
yoke of capitalist pigdogz enslavin us"

Son: "Oh Isee, father jnerula will saveus from the printer and give us free and 
cloud and happy now?"

Dad: "That's right comrade! Join for to us conqueror the worlds!"
