# A  MODERN CMAKE EXAMPLE PROJECT

## Project Structure

Target at:

1. Maintaining a project structure
2. Dealing with third party libraries
3. Could be a libraries itself

```


Project_name
  |
  |---- CMakeLists.txt
  |
  |---- include
  |       |
  |       |---- Project_name
  |                 |
  |                 |---- public_header(s).h
  |
  ---- src
  |     |
  |     |---- private_header(s).h
  |     |---- code(s).cpp
  |			|---- CMakeLists.txt
  |
  |
  |---- lib
          |
          |---- A
          |
          |---- B
          |
          |---- CMakeLists.txt

  
```

## Third Party Libraries Supports

1. Boost
2. OpenMP
3. Opencv4
4. GLFW, GLEW

## Example Static/Shared Library

* Box2d
* … any kind of modern cmake 3rd party library source code.

## Motivation

* Hard to find a suitable cmake template for "medium" projects:

  * suitable for research
  * don't need test & docs 
  * don't want very hard-to-read .cmake. /config. CMakelist is enough for me (because of limited knowledge)

* Need to link 3rd libraries easily

* Can compile on different platform

* Could evolve if the author have the potential to do that ()

  