# Get --output file name
$Output = $args[0]
if ($null -eq $Output) {
    $Output = "sort.exe"
}

$files = Get-ChildItem -Recurse -Filter *.cpp -Path .\src | ForEach-Object { "$($_.FullName)" }
g++ '-Wl,--stack,1000000000' -fdiagnostics-color=always -O3 -g main.cpp $files -o $Output