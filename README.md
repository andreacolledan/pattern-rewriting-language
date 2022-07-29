# Pattern Rewriting Language (PRL)

Experiment on the development of a programming language based on the rewriting of generic symbols in a 2D grid.
It is inspired by the [MarkovJunior](https://github.com/mxgmn/MarkovJunior) project.

## Running PRL

Building PRL requires [meson](https://mesonbuild.com) and [cmake](https://cmake.org) to be installed on your machine. Once you have meson and cmake, clone this repository and initialize its submodules:

```
$ git clone https://github.com/andcol/pattern-rewriting-language
$ cd pattern-rewriting language
$ git submodule init
$ git submodule update
```

Then, you can build the project with

```
$ meson build
$ meson compile -C build
```

Finally, you can execute the (hardcoded, for now) example `islands.prl` by running

```
$ build/prl
```

## Roadmap
This project is still very much WIP. At the moment, only a core set of the language is implemented, and the current roadmap includes the following relevant points:

* Fix efficienncy issues with the current use of `std::vector`
* Producing documentation for the language,
* Implementing visualization of the rewrite process,
* ...