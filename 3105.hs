import Data.List (sort)

main :: IO ()
main = do
    cs <- getLine
    let ds = [ d | d <- takeWhile (/= '.') cs, d `elem` ['0'..'9'] ]
    putStrLn $ reverse $ sort ds

