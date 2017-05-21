[![Version](https://img.shields.io/cocoapods/v/SBTUITestTunnelHost.svg?style=flat)](http://cocoadocs.org/docsets/SBTUITestTunnelHost)
[![License](https://img.shields.io/cocoapods/l/SBTUITestTunnelHost.svg?style=flat)](http://cocoadocs.org/docsets/SBTUITestTunnelHost)
[![Platform](https://img.shields.io/cocoapods/p/SBTUITestTunnelHost.svg?style=flat)](http://cocoadocs.org/docsets/SBTUITestTunnelHost)

## Overview

Apple's UI testing framework is a tremendously powerful tool to write ui tests for your application. There are however some edge cases were tests can become difficult/impossible to write. We've been developing this tool to cover different (at first sight unrelated) needs in our ui testing workflow.

SBTUITestTunnelHost includes a Mac App (Server) and a set of classes to be used in your UI test target which enables to:

- launch shell commands on the Mac host from within the test target. This can come in handy if you have shell scripts that interact with your backend environment (user creation, deletion, content modification and so on)
- perform mouse actions. We use this to perform very fast interaction (i.e. very fast and repeated swipes) with the app under test, which is not possible using XCTest capabilities
- serve static content file. Lift you from installing a full web server when in need to serve simple static content

## Installation (CocoaPods)

We strongly suggest to use [cocoapods](https://cocoapods.org) being the easiest way to embed the library inside your project. You simply need to add `SBTUITestTunnelHost` to your UI Test target. 

## Installation (Manual)

Add files in the *SBTUITestTunnelHost* to the UI test target.

## Usage

### Mac

Launch the Mac App (either by compiling the `Mac Host/SBTUITunnelHostServer.xcworkspace` or launching the executable in `Mac Host/Binary/SBTUITestTunnelServer.zip`) which will fire a server on your local machine on port 8667. The current status of the server will be shown in the macOS menubar.

#### Security Warnings 🔥🔥🔥 

The tool is intended for testing enviornments only, use with care since **it allows to access and execute commands** on the running host. **Make sure that the host is only reachable by trusted clients.**

To increase security by default the application binds the server to localhost. This means that it will only receive requests from within the same machine that runs the tool, which should be fine in most cases. You can optionally launch the application  passing the `--skipLocalhostBinding` or by manually toggling the option from menubar to bypass this limitation.

For additional security launch the tool with a system user with [specific access privileges](https://support.apple.com/kb/PH25796?locale=en_US&amp;viewlocale=en_US)

### UI Tests

In your code just import SBTUITestTunnelHost. This will add a `host` property to the XCTest class which is an instance of `SBTUITestTunnelHost`.

The Example project comes with several Tests in Swift and Objective-C that show the different use cases.

#### launching shell commands
To remotely execute a command invoke  `host.executeCommand(cmd)` which will synchronously execute the command and return the stdout output.

#### mouse actions

You can execute 2 different type of mouse actions: clicks and drags.

##### Clicks




#### serving files
Simply issue a GET request to http://localhost:8667/catfile?token=<TOKEN>&content-type=application/json&path=/tmp/tunnel-test


## Additional resources

If you need to mock or inject data from a UI Test try [SBTUITestTunnel](https://github.com/Subito-it/SBTUITestTunnel).

## Contributions

Contributions are welcome! If you have a bug to report, feel free to help out by opening a new issue or sending a pull request.

## Authors

[Tomas Camin](https://github.com/tcamin) ([@tomascamin](https://twitter.com/tomascamin))

## License

SBTUITestTunnelHost is available under the Apache License, Version 2.0. See the LICENSE file for more info.
