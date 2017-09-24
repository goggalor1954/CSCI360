import os


def run_c(filename):
    import subprocess
    name,ext = os.path.splitext(filename)
    try:
        assert(ext in ['.c','.cpp','.c++'])
    except:
        print "Unrecognized extension.  File must be .c, .cpp, or .c++.  Other filetypes may be supported soon if demand exists."
        raise SystemExit(0)
    compiler = "g++"
    if ext=='.c':
        compiler = "gcc"
    proc = subprocess.Popen("/usr/bin/%s %s -lcrypto -lpthread"%(compiler,filename),shell=True,stdout=subprocess.PIPE,stderr=subprocess.PIPE)
    proc.wait()
    out,err = proc.communicate()
    if err:
        #print repr(err)
        return False,False,repr(err)
    ok = True
    try:
        out = subprocess.check_output("./a.out",shell=True,stderr=subprocess.PIPE)
    except:
        ok = False

    return True,ok,out



import os
root = "./"
assignment = "Project 1"
report = open(assignment+".report.md","w")
path = root
files = os.listdir(path)

report.write("# Assignment %s\n"%assignment)
report.write("\n\n Searching for files: \n\n```\n")
basenames = ["sol_cleaner", "sol_sap", "sol_sac","sol_cracker"]
fullnames = dict()
found_basenames = [False]*len(basenames)
for i,n in enumerate(basenames):
    foundling = [f for f in files if f.find(n)==0]
    exists = len(foundling)==1
    found_basenames[i] = exists
    report.write("%s found: %s\n"%(n,exists))
    if exists:
        fullnames[n]=foundling[0]
    else:
        fullnames[n]=False
report.write("``` \n")
for i,n in enumerate(basenames):
    report.write("\n---\n### Examining %s.\n"%basenames[i])
    if found_basenames[i]==False:
        report.write("File not found\n")
        continue
    before_files = set(os.listdir(path))
    btimes = [os.path.getmtime(path+bf) for bf in sorted(before_files)]
    (compiles,runs,output) = run_c(fullnames[n])
    after_files = set(os.listdir(path))
    atimes = [os.path.getmtime(path+bf) for bf in sorted(before_files)]

    modified = [sorted(before_files)[i] for i in range(len(btimes)) if atimes[i]!=btimes[i]]
    modified.remove("a.out")
    new_files = list(after_files.difference(before_files))
    report.write("Compiles: %s\n\n"%compiles)
    report.write("Runs: %s\n\n"%runs)
    report.write("Terminal Output: %s\n\n"%output)
    report.write("Produced files: "+", ".join(new_files)+"\n\n")
    report.write("Modified files: "+ ", ".join(modified)+"\n\n")
    for m in modified:
        f = open(m,"r").readlines()
        report.write("Excerpt of %s:\n\n```\n\n"%m)
        if len(f)==1:
            report.write(f[0][:80])
        else:
            report.writelines(f[:10])
        report.write("\n```\n\n---\n")
report.close()
