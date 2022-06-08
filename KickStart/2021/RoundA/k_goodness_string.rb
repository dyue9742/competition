# frozen_string_literal: true
def score(arr, num)
  score = 0
  rev = arr.reverse
  case num % 2
  when 0
    (num / 2).times do |index|
      score += 1 unless arr[index] == rev[index]
    end
  when 1
    ((num - 1) / 2).times do |index|
      score += 1 unless arr[index] == rev[index]
    end
  end
  score
end

def solve
  d = {}
  test_case = gets.chomp.to_i
  test_case.times do |index|
    n, k = gets.chomp.split(' ')
    str = gets.chomp
    d[index] = (score(str.split(''), n.to_i) - k.to_i).abs
  end
  d.each_pair do |key, value|
    puts "Case ##{key + 1}: #{value}"
  end
end
