import Data.List (delete, find)

getLines :: IO [String]
getLines = lines <$> getContents

main :: IO ()
main = do
    ls <- getLines
    let n = read (head ls) :: Int
        values = map read $ take n $ tail ls :: [Int]
        indexed = zip [1..] values
        influential = filter (\(_,v) -> v /= 0) indexed
        sum' = sum $ map snd influential
        evenSet = if even sum'
                  then influential
                  else case find (odd.snd) influential of
                         Just n -> delete n influential
    print $ map fst evenSet

