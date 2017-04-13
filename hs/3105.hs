import Data.List (sort)

main :: IO ()
main = do
    cs <- getLine
    let ds = [ d | d <- takeWhile (/= '.') cs, d `elem` ['0'..'9'] ]
    if length ds == 0
       then putStrLn "-1"
       else putStrLn $ reverse $ sort ds

