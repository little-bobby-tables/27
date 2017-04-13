import qualified Data.Map as Map
import Data.List (sortBy)
import Data.Function (on)

getLines :: IO [String]
getLines = lines <$> getContents

printList :: (Show a) => [(a, a)] -> IO ()
printList [] = return ()
printList (x:xs) = do
  putStrLn $ show (fst x) ++ " " ++ show (snd x)
  printList xs 

main :: IO ()
main = do
  ls <- getLines
  let n = read $ head ls :: Int
      entries = map read $ take n $ tail ls :: [Int]
      grouped = Map.toList $ foldr (\x acc -> Map.insertWith (+) x 1 acc) Map.empty entries
      sorted = sortBy (flip (compare `on` snd)) grouped
  printList sorted

