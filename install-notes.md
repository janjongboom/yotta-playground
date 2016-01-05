* `pip` is not installed with `brew install python`, need to run `sudo easy_install pip`
* Hidapi fails to install

```
    building 'hid' extension
    error: unknown file type '.pxd' (from 'chid.pxd')
    
    ----------------------------------------
Command "/usr/bin/python -c "import setuptools, tokenize;__file__='/private/var/folders/23/tsgskn7n75d8jc07yf2fs2n08gb5z6/T/pip-build-67POr5/hidapi/setup.py';exec(compile(getattr(tokenize, 'open', open)(__file__).read().replace('\r\n', '\n'), __file__, 'exec'))" install --record /var/folders/23/tsgskn7n75d8jc07yf2fs2n08gb5z6/T/pip-kSpd_1-record/install-record.txt --single-version-externally-managed --compile" failed with error code 1 in /private/var/folders/23/tsgskn7n75d8jc07yf2fs2n08gb5z6/T/pip-build-67POr5/hidapi
```

* `pip install cython` fixes the problem
* Why is there a link to register, argh
* Sorry, something went wrong. No verified emails found. Verify your email at https://developer.mbed.org/account/settings/
* Click on the link, and select 'Resend email'
* No email yet after 5 minutes
* Change my email to my @arm.com address...
* Still no email
* Oh after 10 minutes finally an email
* Andddddd my Auth is now timed out #*($
* OK. Done. Now it's installed
* `mbed-drivers` should be listed as standard dependency when running `yotta init` i think
* `yotta build` fails

```
info: generate for target: frdm-k64f-armcc 2.0.0 at /Volumes/repos/yotta-blinky/yotta_targets/frdm-k64f-armcc
warning: error detecting build info: "command failed: fatal: ambiguous argument 'HEAD': unknown revision or path not in the working tree.", build info is not available to the build. Please check that this is a valid Git repository!
**************************************************************************

 ERROR: the arm toolchain program armcc could not be found.

 Note that the armcc toolchain is not available for Max OS X.

**************************************************************************
CMake Error at /Volumes/repos/yotta-blinky/yotta_targets/mbed-armcc/CMake/toolchain.cmake:44 (message):
  missing program prevents build
Call Stack (most recent call first):
  /Volumes/repos/yotta-blinky/yotta_targets/mbed-armcc/CMake/toolchain.cmake:49 (arm_toolchain_program_notfound)
  toolchain.cmake:8 (include)
  /usr/local/Cellar/cmake/3.4.1/share/cmake/Modules/CMakeDetermineSystem.cmake:98 (include)
  CMakeLists.txt:138 (project)


CMake Error: CMAKE_C_COMPILER not set, after EnableLanguage
CMake Error: CMAKE_CXX_COMPILER not set, after EnableLanguage
-- Configuring incomplete, errors occurred!
error: command ['cmake', '-D', 'CMAKE_BUILD_TYPE=RelWithDebInfo', '-G', 'Ninja', '.'] failed
```

Questions:

1. Can you only use yotta in a git repo or something??
2. What does: 'Note that the armcc toolchain is not available for Max OS X' mean? I can't use yotta on OS/X?
3. I have `arm-none-eabi-gcc` already so what does it mean????
4. Side note: Why does `yotta init` do a `git add` on module.json hmm...

And now I'm blocked.

* OK. So the issue was selecting the wrong target. 
* We should give a big fat warning on OS/X when selecting a armcc target
* `yotta build` now works.
* We should have a `yotta deploy` or something
* Why is the output in `source` and not in `out`?
* OK. Nice, it works.