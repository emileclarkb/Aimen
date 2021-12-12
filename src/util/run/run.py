# Assets
import os
import sys
import json

# Constant Declarations
save = True
gcc = False
out = 'aimen'
extensions = ['cpp']
link = []
#include = [os.getcwd()] #include base directory?
blacklist = ['gen']


# directory marching
def march(path, blacklist):
    files = []
    for i in os.listdir(path):
        if i not in blacklist:
            f = f'{path}\{i}'
            if os.path.isdir(f):
                files.extend(march(f, blacklist))
            else:
                if i.split('.')[-1] in extensions:
                    files.append(f)
    return files

def main():
    # move to main directory
    os.chdir('../..')

    # get files
    cwd = os.getcwd()
    files = march(cwd, blacklist)
    files = [f.replace(cwd+'\\', '') for f in files]

    # generate command
    # -std=c++11
    cmd = 'gcc' if gcc else 'g++'
    cmd = f'{cmd} {" ".join(files)} -o {out} ' + \
            ' '.join(f'-l{l}' for l in link) + ' ' + \
            ' '.join(f'-I{i}' for i in [cwd])

    # compile and run
    os.system(cmd)

    exe = f'{out}.exe'
    if os.path.exists(exe):
        os.system(out)

        # delete binary file
        if not save:
            os.remove(exe)


if __name__ == '__main__':
    try:
        main()
    except KeyboardInterrupt:
        clean()
