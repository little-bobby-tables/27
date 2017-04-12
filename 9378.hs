import Data.Function (on)
import Data.List (find, sortBy)

getLines :: IO [String]
getLines = lines <$> getContents

main :: IO ()
main = do
  ls <- getLines
  let n = read $ head ls :: Int
      values = map read $ take n $ tail ls :: [Int]
      indexed = zip [1..] values
      filtered = filter (\(_, val) -> val > 0) indexed
      sorted = sortBy (compare `on` snd) filtered
      (minTime, minValue) = head sorted
      timeLimited = filter (\(t, _) -> t > minTime + 5 || t < minTime - 5) sorted
      result = if even minValue
                  then minValue * (snd $ sorted !! 1)
                  else case find (even . snd) timeLimited of
                         Just t -> minValue * snd t
                         Nothing -> -1
  print result
