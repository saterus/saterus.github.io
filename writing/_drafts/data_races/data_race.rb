def do_work(work_log)
  10_000.times do
    work_log[:counter] += 1
  end
end

log = { counter: 0 }
puts "Work Log: #{log}"

worker_a = Thread.new { do_work(log) }
worker_b = Thread.new { do_work(log) }

worker_a.join
worker_b.join

puts "Work Log: #{log}"
