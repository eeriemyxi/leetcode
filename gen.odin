// Compile with: odin build gen.odin -file

package gen

import "core:flags"
import "core:fmt"
import "core:os/os2"
import "core:text/regex"

Options :: struct {
	p: string `args:"pos=0" usage:"Name of the problem. Or link."`,
	e: string `usage:"Extension of the solution file. Defaults to 'cpp'."`,
}

opt: Options

find_link :: proc(text: string) -> (result: string, ok: bool) {
	pattern :: `https?:\/\/leetcode.com\/problems\/([a-z,A-Z,\-]+)\/?`
	iter, err := regex.create_iterator(text, pattern)
	ensure(err == nil, "Bad regex.")
	for match in regex.match_iterator(&iter) {
		return match.groups[1], true
	}
	return "", false
}

main :: proc() {
	opt.e = "cpp"

	style: flags.Parsing_Style = .Odin
	flags.parse_or_exit(&opt, os2.args, style)

	exec_dir, exderr := os2.get_executable_directory(context.temp_allocator)
	ensure(exderr == nil, "Couldn't get executable directory.")

	if len(opt.p) == 0 {
		fmt.eprintfln("ERROR: Problem name wasn't provided. Please check -h or -help.")
		os2.exit(1)
	}

	problem, ok := find_link(opt.p)
	if ok {
		fmt.printfln("[INFO] Transformed %s -> %s", opt.p, problem)
	} else {
		problem = opt.p
	}

	prob_path, jperr := os2.join_path({exec_dir, problem}, context.temp_allocator)
	ensure(jperr == nil, "Couldn't join paths.")

	sol_fname := fmt.tprintf("sol.%s", opt.e)
	sol_fpath, jpserr := os2.join_path({prob_path, sol_fname}, context.temp_allocator)
	ensure(jpserr == nil, "Couldn't join paths.")

	derr := os2.mkdir(prob_path)
	if derr != nil {
		if derr == .Exist {
			fmt.eprintfln("ERROR: Path '%s' already exists.", prob_path)
		} else {
			fmt.printfln("ERROR: couldn't create directory '%s': %v", prob_path, derr)
		}
		os2.exit(1)
	}
	fmt.printfln("[INFO] Created directory '%s'", prob_path)

	file, ferr := os2.create(sol_fpath)
	if ferr != nil {
		fmt.printfln("ERROR: couldn't create file '%s': %v", sol_fname, ferr)
		os2.exit(1)
	}
	fmt.printfln("[INFO] Created file '%s'", sol_fpath)
    
    prob_readme_path, jprerr := os2.join_path({prob_path, "README.md"}, context.temp_allocator)
    ensure(jprerr == nil, "Couldn't join paths.")
    
    rfile, rferr := os2.open(prob_readme_path, {.Write} | {.Create}, os2.Permissions_Default_File)
	if rferr != nil {
		fmt.printfln("ERROR: couldn't open file '%s': %v", prob_readme_path, rferr)
		os2.exit(1)
	}
	defer os2.close(rfile)

    n, rwerr := os2.write_string(rfile, fmt.tprintf("Problem: %s\n", opt.p))
	if rwerr != nil {
		fmt.printfln("ERROR: couldn't write to file '%s': %v", prob_readme_path, rwerr)
		os2.exit(1)
	}
	fmt.printfln("[INFO] Wrote %d bytes to file '%s'", n, prob_readme_path)
}
