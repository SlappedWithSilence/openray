# OpenRay

OpenRay is a simple Ray-tracer built just for fun using bare C++20. Unit testing is supplied by [Google Test](https://google.github.io/googletest/).
In the future, I hope to add all manner of features and optimizations.

# Running OpenRay From Source

### Windows 10-11
- Clone this repository: `git clone https://github.com/SlappedWithSilence/openray`
- Install Chocolatey: https://chocolatey.org/install
- Install Mingw, CMake, Ninja
  - `choco install mingw`
  - `choco install cmake`
  - `choco install ninja`

# Testing OpenRay
*Please be aware, I am new to the C++ toolchain! CMake is kind of confusing, and as such, my instructions may not be very good.
If you are able to generate better ones, feel free to share them with me.*

OpenRay's unit tests are written using Google Test, a C++ xUnit framework. Google Test is available for Bazel and CMake. OpenRay currently makes use of only CMake.
### Windows 10-11


# References
- **[Ray Tracing Overview](https://www.scratchapixel.com/lessons/3d-basic-rendering/introduction-to-Ray-tracing/)**
- **[Google Test Framework Setup](https://stackoverflow.com/questions/33638433/setup-google-test-in-clion)**
- **[Using Google Test](https://google.github.io/googletest/)**