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

Finally, you can run a PRL program `program.prl` by navigating to the `build` folder and running

```
$ prl program.prl
```

Some example programs are included in the `examples` folder. For a list of supported command-line options, run
```
$ prl --help
```

## The PRL language

PRL is based on the **rewriting** of patterns of **user-defined symbols** in a **2-dimensional field**. Therefore, a typical PRL program consists of three sections.

### Symbol declarations

The symbol declarations always come first. They begin with the keyword `Symbols`, followed by a list of user-selected symbols. For example,
```
Symbols ~, c, #, +
```
declares 4 symbols which can then be used in the rest of the program. At the moment, symbols are limited to single ASCII symbols exluding `'('`,`')'`,`','`,`'-'`,`'>'`,`'*'` and digits.

### Rule section

The rule section begins with the keyphrase `Apply rules`. It contains the definitions of the rules that determine the actual behavior of the PRL program.

#### Rule syntax

In a nutshell, a rule rewrites an occurrence of a pattern in the field to a different pattern. The general aspect of a rule is therefore the following
```
<lhs> -> <rhs>
```
Which states that whatever pattern is described by `<lhs>` gets changes to `<rhs>`.
A more concrete and useful example is the following rule from the `islands.prl` example:
```
c~ -> #c
```
This rule matches any of the following arrangements of symbols in the field
```
c~  ~   ~c  c
    c       ~
```
and respectively rewrites them to
```
#c  c   c#  #
    #       c
```
Naturally, rules can rewrite patterns of any size. The only natural limitations is that the patterns must be of rectangular shape and that the left-hand side and the right-hand side of a rule must have the same shape and size. In the case of multi-line patterns, a rule looks like this
```
~#~
### ->  ~~~
        ###
```
Note: rules rewriting multi-line patterns *must* be separated by an empty line to parse correctly.

#### Exhaustible rules

By default, a rule can be applied an arbitrary number of times. It is possible to define a rule which can only be applied a limited number of times (called an *exhaustible rule*) by specifying its maximum number of uses in its arrow. For example, the following rule can rewrite `~` to `c` at most 5 times
```
~ -5> c
```

#### Rule behavior
A PRL program usually specifies multiple rules in sequence. For example, `islands.prl` specifies 6 rules:
```
~ -5> c
c~ -> #c
c -> #
#~ -> #+
#++# -> ####
#+# -> ###
```
The order of the rules matters. Specifically, the behavior of a sequence of rules is the following:

1. Starting from the top, the rule sequence is scanned until a rule is found which a) has not yet been exausted and b) matches the field in at least one place. If no such rule is found, the program terminates.
2. If such a rule is found, it is applied to one of the possible locations in the field that match it. The specific location is selected randomly.
3. The process resumes from step 1.

Note: the fact that the location of a rule's application is selected randomly among all the possible candidates means that two runs of the same program rarely produce the same result.


### Starting field declaration

A PRL program must specify the initial state of the field before any rule is applied to it. The declaration of the starting field begins with the keyphrase `Starting from`, followed by the initial state, for example:
```
Starting from
~~~~~~~~~~~~~~~~~~~~
~~~~~~~~~~~~~~~~~~~~
~~~~~~~~~~~~~~~~~~~~
~~~~~~~~~~~~~~~~~~~~
~~~~~~~~~~~~~~~~~~~~
```
Alternatively, if the starting field is filled with just one symbol like in the example above, the following shorthand syntax can be employed, which yields the same result:
```
Starting from ~ (5,20)
```
Note that the field's height comes first and its width second. For more information on PRL's syntax, refer to the examples in the `examples` folder.

### Comments

At the moment, only single-line comments are supported. Comments are introduced by `//`. For example:
```
Symbols a, b
Starting from a (20,20) //Begin with only 'a's

Apply rules

//Turn all 'a's into 'b's
a -> b
```

## Visualization

At the moment, the only way to visualize the output of a PRL program is by having it printed to the standard output (default behavior). In order to avoid distorsion, it is suggested to employ a square font such as [Square](https://strlen.com/square/) when doing so.

## Roadmap
This project is still very much WIP. At the moment, only a core set of the language is implemented, and the current roadmap includes the following relevant points:

* Finish implementing and testing wildcards,
* Implement rule blocks
* Implement visualization of the rewrite process,
* ...