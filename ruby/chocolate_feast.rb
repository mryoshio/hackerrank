def solve(_n, _c, _m)
  v, m = _n.divmod(_c)
  v2, m2 = v.divmod(_m)
  puts v + v2 + (m2 + v2) / _m
end

while str = STDIN.gets
  l = str.chomp.split(/\s/).map { |v| v.to_i }
  solve(l[0], l[1], l[2]) if l.size == 3
end
