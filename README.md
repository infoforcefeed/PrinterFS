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
