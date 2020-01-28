(TeX-add-style-hook
 "DesignDocument"
 (lambda ()
   (TeX-add-to-alist 'LaTeX-provided-class-options
                     '(("article" "12pt")))
   (TeX-run-style-hooks
    "latex2e"
    "article"
    "art12"
    "titlesec"
    "hyperref")
   (LaTeX-add-counters
    "subsubsubsection"))
 :latex)

