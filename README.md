## Test task for the position of C++ developer

The project is written on the _MacOS_ operating system and uses the _GSS_ compiler and using _C++17_ standart.

### _Mikefiles_ are used to build the project:
- To build a library `curve3D` use the `make` command in the directory `.../Curve/lib`.
- To build the project, use the `make` command in the root directory `.../Curve`.

To run use the `./curve` command in the root directory `.../Curve`.

---

## Task Description

### Design a small program in C++ that would implement support of 3D curves hierarchy.

- Support a few types of 3D geometric curves – _circles_, _ellipses_ and _3D helixes_. (Simplified definitions are below). Each curve should be able to return a 3D point and a first derivative (3D vector) per parameter `t` along the curve.
- Populate a container (e.g. vector or list) of objects of these types created in random manner with random parameters.
- Print coordinates of points and derivatives of all curves in the container at `t = PI/4`.
- Populate a second container that would contain only circles from the first container. Make sure the second container shares (i.e. not clones) circles of the first one, e.g. via pointers.
- Sort the second container in the ascending order of circles’ radii. That is, the first element has the smallest radius, the last - the greatest.
- Compute the total sum of radii of all curves in the second container.

(*) Additional optional requirements:
- Split implementation into a library of curves (_.dll or .so_) and executable which uses API of this library.
- Implement computation of the total sum of radii using parallel computations (e.g. _OpenMP or Intel TBB library_).


### Requirements to the implementation:

- The implementation must use **virtual methods**.
- Has neither explicit memory deallocation nor memory leaks.
- Curves must be physically correct (e.g. radii must be positive).
- Containers and sorting must be implemented using **STL** (_C++ Standard Template Library_).
- The implementation may use constructs of _C++11_ or higher.
- The code must compile with any compiler of your choice (_gcc, Visual C++, etc_).


### Curve definitions:

- All curves are parametrically defined, i.e. a point is calculated using some `C(t)` formula.
- _Circle_ is planar in the plane `XoY` (i.e. all Z-coordinates are 0) and is defined by its radius.
- _Ellipse_ is planar in the plane `XoY` and is defined by its two radii, along **X** and **Y** axes.
- _Helix_ is spatial and is defined by its radius and step (see the figure below). It takes `2 * PI` in parametric space to make a round, i.e. any point on helix satisfies the condition `C(t + 2*PI) = C(t) + {0, 0, step}`.