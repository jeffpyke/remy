[![Build Status](https://travis-ci.org/tcpexmachina/remy.svg?branch=master)](https://travis-ci.org/tcpexmachina/remy)

Remy: TCP ex Machina (computer-generated congestion control)
============================================================

Author's instructions:

Remy is an optimization tool to develop new TCP congestion-control
schemes, given prior knowledge about the network it will encounter
and an objective to optimize for.

It is described further at the Web site for [TCP ex
Machina](http://web.mit.edu/remy). A research paper on Remy was
published at the ACM SIGCOMM 2013 annual conference.

Basic usage:

* Remy requires a C++11 compiler to compile, e.g. gcc 4.6 or
  contemporary clang++. You will also need the Google
  protobuf-compiler and the Boost C++ libraries.

* From the version-control repository checkout, run `./autogen.sh`,
  `./configure`, and `make` to build Remy.

* Run `./remy` to design a RemyCC (congestion-control algorithm) for
  the default scenario, with link speed drawn uniformly between 10 and
  20 Mbps, minRTT drawn uniformly between 100 and 200 ms, the maximum
  degree of multiplexing drawn uniformly between 1 and 32, and each
  sender "on" for an exponentially-distributed amount of time (mean 5
  s) and off for durations drawn from the same distribution.

* Use the of= argument to have Remy save its RemyCCs to disk. It will
  save every step of the iteration.

* Use the if= argument to get Remy to read previous RemyCCs as the
  starting point for optimization.

* The `sender-runner` tool will execute saved RemyCCs. The filename
  should be set with a `if=` argument. It also accepts `link=` to set
  the link speed (in packets per millisecond), `rtt=` to set the RTT,
  and `nsrc=` to set the maximum degree of multiplexing.

If you have any questions, please visit [Remy's Web
site](http://web.mit.edu/remy) or e-mail `remy at mit dot edu`.

-- Keith Winstein

Reproduction Resources:

* All the dna files used for our results are present in `dna_files` folder

* The configurations used for 2018 runs are present in `configurations` folder

* Window transformation parameters can be adjusted in `src/whiskers.hh`

To produce the graphs:

We have updated the `tests/run-plot-script.py` to produce results in `tests/plot-results`. A new trained algorithm can be plotted in following way:

* Using `make`
  * Update `REMYCC_NAME` in `tests/run-plot-script.py`
  * Run `make -j check` (this also runs additional checks)

* Calling the script directly
  * Update `REMYCC_NAME` in `tests/run-plot-script.py`
  * Setup srcdir variable using `export srcdir=<path to remy>/remy/tests`
  * Run `./run-plot-scripts.py`

The resultant csv file is generated in `tests/plot-results/data`. We used this method to generate score for individual rule files and then used separte python script to combine them together. The script can be found in `tests/plot-results/data/plot.ipynb`
