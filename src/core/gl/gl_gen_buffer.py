import re, json

funcs = {}
ext_suffix = ['ARB', 'EXT', 'KHR', 'OVR', 'NV', 'AMD', 'INTEL']

def is_ext(proc):
    return any(proc.endswith(suffix) for suffix in ext_suffix)

p = re.compile(r'GLAPI.*APIENTRY\s+(\w+)')

def camel_to_snake(name):
    name = re.sub('(.)([A-Z][a-z]+)', r'\1_\2', name)
    return re.sub('([a-z0-9])([A-Z])', r'\1_\2', name).lower()

with open("../external/glcorearb.h", 'r') as f:
    for line in f:
        m = p.match(line)
        if not m:
            continue
        proc = m.group(1)
        if not is_ext(proc):
            new_name = camel_to_snake(proc[2:])
            funcs[proc] = new_name

for i in funcs:
    print(i, funcs[i])

f = open("generated/function_names.json", 'w')
json.dump(funcs, f)
f.close()