c:\tools\resharper.cli\inspectcode.exe --toolset=16.0 --output=results.xml sample.sln
resharper2sarif.exe results.xml results.sarif
git add results.sarif