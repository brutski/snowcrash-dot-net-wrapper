snowcrash-dot-net-wrapper
=========================
.NET wrapper for snowcrash parser: https://github.com/apiaryio/snowcrash

## Forks note

This fork has been created with purpose of building it on AppVeyorn, autogenerate a nuget package and push it on the repository.
Some modifications were necessary to fit my needs. Here is in particular what I have done and what I want to do.

- [x] Change the submodule to use public repository URL
- [x] Update the wrapper to the latest snowcrash version
- [x] Change configuration for Release version of DLL (it does not compile)
- [ ] Make it compile on AppVeyorn  [![Build status](https://ci.appveyor.com/api/projects/status/3d0a3hebo6u2jo1w)](https://ci.appveyor.com/project/XVincentX/snowcrash-dot-net-wrapper)
- [ ] Find a way to make it AnyCPU compatible
- [ ] Create a nuget package and autopush on it
- [ ] Can we do something to support Mono and Unix as well?
- [ ] Full managed implementation ?!


