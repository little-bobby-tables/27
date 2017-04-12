import Data.List (partition)

getLines :: IO [String]
getLines = lines <$> getContents

parseInput :: String -> (Int, Int)
parseInput s =
  let ws = words s in (read (ws !! 2), read (ws !! 3))

computeAvg :: [(Int, Int)] -> [(Int, Int)]
computeAvg [] = []
computeAvg (x:xs) = 
  let school = fst x
      (same, rest) = partition (\(s, _) -> s == school) xs
      schoolStats = x : same
      scores = map snd schoolStats
      avg = sum scores `div` length scores
  in (school, avg) : computeAvg rest

main :: IO ()
main = do
  ls <- getLines
  let n = read $ head ls :: Int
      parsed = map parseInput $ take n $ tail ls
      stats = computeAvg parsed
      maxAvg = maximum $ map snd stats
      havingMax = filter (\(_, avg) -> avg == maxAvg) stats
  if length havingMax == 1
     then putStrLn $ show (maxAvg) ++ " in school #" ++ show (fst $ head havingMax)
     else putStrLn $ show (maxAvg) ++ " in " ++ show (length havingMax) ++ " schools"

