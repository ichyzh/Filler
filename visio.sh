p1=$(printf "⚽")
p2=$(printf "🏀")
s1=$(printf "🥇")
s2=$(printf "🌝")
field=$(printf "🌚")


sed "s|O|$p1|g" |
sed "s|X|$p2|g" |
sed "s|x|$s1|g" |
sed "s|*|$s2|g" |
sed "/^0.. /s|o|$s1|g" |
sed "s|\.|$field|g" | 
sed "s|fin|player|g"
