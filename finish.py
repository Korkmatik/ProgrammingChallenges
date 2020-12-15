######################################################################################
#                                                                                    #
# This Script automates the creation of a README file for a given challenge          #
#                                                                                    #
# Usage: python finish.py [challenge name] [challenge URL]                           #
#                                                                                    #
######################################################################################

import sys
import os

if len(sys.argv) < 3:
    print("Usage: %s [challenge name] [challenge URL]"  % sys.argv[0])
    sys.exit(0)

challenge_name = sys.argv[1].split(" ")
challenge_name = "".join(list(map(lambda name: name.capitalize(), challenge_name)))

challenge_url = sys.argv[2]

CODEFORCES_PATH = "CodeForces"

path = ""
if "codeforces.com" in challenge_url:
    path =  CODEFORCES_PATH

path = os.path.join(path, challenge_name)

FILE_NAMES = ["main.c", "main.cpp"]
for file_name in FILE_NAMES:
    test_path = os.path.join(path, file_name)
    if os.path.isfile(test_path):
        f = file_name
        break

readme_file_path = os.path.join(path, "README.md")

with open(readme_file_path, "w") as readme:
    readme.write("# Challenge\n")
    readme.write(f"Link: {challenge_url}\n\n")
    readme.write("# How To Compile:\n")

    compiler = "gcc"
    if f.find(".cpp") != -1:
        compiler = "g++"

    readme.write(f"`{compiler} {f}`\n")
