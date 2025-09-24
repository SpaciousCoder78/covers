<h1 align="center">covers</h1>
<p align="center">
    <img src="https://codeberg.org/avatars/9c46972b6419c609a4e5d5fc02cb6b53a4eddf08a7378d79f1ae9ed7c41b8090?size=200" height="75" width=auto>
    <br>
</p>
<h3 align="center">A Package/Library Manager for C</h3>

`covers` is a Package/Library Manager for C to help you install curated C libraries into your project.

`covers` is still in its Beta phase with a lot of features planned.
 
## Submit a Carriage(Package)
To submit a Carriage(also called package) to `covers`, just open an issue in this <a href="https://codeberg.org/covers/submitcarriages/issues" target="_blank">repository</a>.

## Installation

`covers` can be built from source on GNU/Linux, MacOS or any Unix-like operating system.

`covers` requires `git` and `make` to be pre-installed.

- Clone this repository

```$ git clone https://codeberg.org/covers/covers.git```

- `cd` into the cloned repository

```$ cd covers```

- Use GNU Make to install covers using Makefile targets (needs root)

```$ make```

- To remove `covers` from your system, run the following command

```$ make remove```

### Building from source for development

If you wish to use a dev build of `covers`, follow these instructions

- Clone this repository

```$ git clone https://codeberg.org/covers/covers.git```

- `cd` into the cloned repository

```$ cd covers```

- Use GNU Make to run the dev build script

```$ make build-dev```

- To remove the dev build from source, use this command

```$ make clean```

## User Manual

### Nomenclature

`covers` is derived from a local Indian English word 'cover' which refers to a plastic bag that's used to carry something.

Carriage (again a local Indian English word) is a cover with some items in it (usually lunch).

In software terms, `covers` is a package manager and Carriage is a package carried by `covers`.

### Usage

As of v0.1.0, `covers` only supports two commands:

To check the version and information about `covers`:

```$ covers version -v```

To install a Carriage from the <a href="https://codeberg.org/covers">Official Package Repository </a>:

```$ covers install carriagename```

## Why I made this + Contributing

I, SpaciousCoder78, developed `covers` as a hobby project to learn C for development use. I soon found out that it can be a useful tool so I went ahead with turning it into a free software project.

`covers` is 100% free software and is developed using free software tools.

This project could've been implemented in a much higher level language like Perl or Python but I wanted it to be a challenge and wanted to learn C so I wrote it entirely in C with hours of debugging with help from #c on Libera.chat and not using LLMs for anything in this project.

This project is hereby 100% free as well as LLM-free so no contributions should have any usage of LLMs. 

Further contribution guidelines will be introduced once `covers` is developed further.

## License

Totally free software backed by MIT License


## Logo Attribution

<a href="https://www.flaticon.com/free-icons/plastic-bag" title="plastic bag icons">Plastic bag icons created by Luvdat - Flaticon</a>