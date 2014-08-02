snowcrash-dot-net-wrapper
=========================
.NET wrapper for snowcrash parser: https://github.com/apiaryio/snowcrash

## Forks note

This fork has been created with purpose of building it on AppVeyorn, autogenerate a nuget package and push it on the repository.
Some modifications were necessary.

1. Change snowcrash submodule url to public one instead of the old, due to some public key issues
2. Update snowcrash to latest commits. From 0.7 we're now at 0.12, it's time to jump forward!


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

## Contributors

This project made possible in part by [Medidata Solutions](http://twitter.com/medidata)

V.Chianese for the nuget package :)


