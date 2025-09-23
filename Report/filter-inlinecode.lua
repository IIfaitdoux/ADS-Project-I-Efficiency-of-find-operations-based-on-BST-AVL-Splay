-- Wrap inline code with a gray background using \texttt and \detokenize
-- so font macro expansion won't produce invalid control sequences.
function Code(elem)
  -- Use \texttt (monospace) to avoid expanding custom font macros here.
  local latex = "\\colorbox{gray!10}{\\codefont\\textcolor{orange}{\\detokenize{" .. elem.text .. "}}}"
  return pandoc.RawInline('latex', latex)
end