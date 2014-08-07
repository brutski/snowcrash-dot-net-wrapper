snowcrash-dot-net-wrapper
=========================

.NET wrapper for snowcrash parser: https://github.com/apiaryio/snowcrash

# Building

1. Clone using GitHub client or git in Git shell:
	* `git clone git@github.com:brutski/snowcrash-dot-net-wrapper.git`
2. Update submodules:
	* `cd snowcrash-dot-net-wrapper` 
	* `git submodule update --init --recursive`
3. Build snowcrash first:
	* For Win32 `snowcrash\vcbuild.bat` or `snowcrash\vcbuild.bat x64` for x64 platform

Now, open `snowcrash-dot-net-wrapper.sln` solution in Visual Studio and build. Make sure to use the same Win32/x64 platform for every project in solution's Configuration Manager.

To execute tests make sure to specify `snowcrashCLR.tests\snowcrashCLR.runsettings` 
in `Test->Test Settings->Select Test Settings File` Visual Studio menu.

## Recent changes
### 07/08/2014
- [x] Change the submodule to use public repository URL
- [x] Update the wrapper to the latest snowcrash version
- [x] Change configuration for Release version of DLL (it does not compile, actually)
- [x] Make it compile on AppVeyorn  [![Build status](https://ci.appveyor.com/api/projects/status/3d0a3hebo6u2jo1w)](https://ci.appveyor.com/project/brutski/snowcrash-dot-net-wrapper)
- [x] Create a [nuget package](https://www.nuget.org/packages/Snowcrash.NET/) and autopush on it (**x86** only for now) [![Nuget counter](http://img.shields.io/nuget/dt/Snowcrash.NET.svg)](https://ci.appveyor.com/project/brutski/snowcrash-dot-net-wrapper)
- [x] Run a code analisys on the entire project (removed disposable warnings)



## Contributors

This project made possible in part by [Medidata Solutions](http://twitter.com/medidata). And, of course, thanks to all the [contributors][].

[contributors]: https://github.com/brutski/snowcrash-dot-net-wrapper/graphs/contributors