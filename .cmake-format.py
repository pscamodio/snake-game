# Options affecting cmake-format global parsing
with section("parse"):
  additional_commands = {
    # Prevent cmake-format from lowercasing CPMAddPackage and similar macros
    "CPMAddPackage": {}
  }

with section("format"):
  max_pargs_hwrap = 2
