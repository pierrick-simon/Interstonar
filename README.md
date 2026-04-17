# Interstonar (v0.1)

### Development

By *Ariel Amriou*(ariel.amriou@epitech.eu) and *Pierrick Simon*(pierrick.simon@epitech.eu).

## Objective

Global mode:
Create a space simulation predicting stars and planets position and speed trought time.

Local mode:
Predict where a rock will lan in an asteroid field.


## Getting Started

### Prerequisites

This project requires the following dependencies:

- **Programming Language:** C++

## Requirements

- C++20
- Makefile

### Installation for Linux

1. **Clone the repository:**

```sh
git clone git@github.com:pierrick-simon/Interstonar.git
```

2. **Navigate to the project directory:**

```sh
cd Interstonar
```

3. **compile project:**

```sh
make
```

4. **use program:**

```sh
./interstonar [--global | --local] CONFIG_FILE [-d TIME | --delta=TIME] Px Py Pz Vx Vy Vz
```

A. **global mode:**

For exemple:

```sh
./interstonar --global tests/example/global_scene_example.toml --delta=5000 1 2 3 4 5 6
```

A. **local mode:**

For exemple:

```sh
./interstonar --local tests/example/local_scene_example.toml 10 0 35 -1 0 -2
```

For exemple:

```sh
./interstonar --local tests/example/local_scene_example.toml 10 0 35 -1 0 -2
```

## License

This project is licensed under the **Creative Commons Attribution-ShareAlike 4.0 International License** (CC BY-SA 4.0 DEED).

![Interstonar - Project license](doc/License_AttributionShareAlike_4.0_International.png)
