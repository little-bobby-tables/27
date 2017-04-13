getLines :: IO [String]
getLines = lines <$> getContents

main :: IO ()
main = do
  (n:is) <- getLines
  let count = read n :: Int
      values = map read $ take count is :: [Int]
      expectedR = read $ is !! count :: Int
      oddValues = filter odd values
      evenValues = filter even values
      realR = if length oddValues > 0 && length evenValues > 0
                 then minimum oddValues + minimum evenValues
                 else -1
  if expectedR == realR
     then do
       putStrLn $ "Calculated R: " ++ show (realR)
       putStrLn "Calculated R matches the expected value."
     else do
       putStrLn $ "Calculated R: " ++ show (realR)
       putStrLn "Calculated R does not match the expected value."

